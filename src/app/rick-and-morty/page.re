// [@mel.config {flags: [|"--preamble", "\"use client\";"|]}];

type metadata = {
  title: string,
  description: string,
};
let metadata = {
  title: "Rick & Morty Characters",
  description: "View Rick & Morty characters",
};

type origin = {
  name: string,
  url: string,
};
type location = {
  name: string,
  url: string,
};
type url = string;

type character = {
  id: int, // The id of the character.
  name: string, // The name of the character.
  status: string, // The status of the character ('Alive', 'Dead' or 'unknown').
  species: string, // The species of the character.
  type_of_character: string, // The type or subspecies of the character.
  gender: string, // The gender of the character ('Female', 'Male', 'Genderless' or 'unknown').
  origin, // Name and link to the character's origin location.
  location, // Name and link to the character's last known location endpoint.
  image: url, // Link to the character's image. All images are 300x300px and most are medium shots or portraits since they are intended to be used as avatars.
  episode: array(url), // List of episodes in which this character appeared.
  url, // Link to the character's own URL endpoint.
  created: string // Time at which the character was created in the database.
};

type info = {
  count: int,
  pages: int,
  next: url,
  prev: option(url),
};

type characters_object_data = {
  info,
  results: array(character),
};

let decodeOrigin = (json): origin => {
  Json.Decode.{
    name: json |> field("name", string),
    url: json |> field("url", string),
  };
};

let decodeLocation = (json): location => {
  Json.Decode.{
    name: json |> field("name", string),
    url: json |> field("url", string),
  };
};

let decodeCharacter = (json): character =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    status: json |> field("status", string),
    species: json |> field("species", string),
    type_of_character: json |> field("type", string),
    gender: json |> field("gender", string),
    origin: json |> field("origin", decodeOrigin),
    location: json |> field("location", decodeLocation),
    image: json |> field("image", string),
    episode: json |> field("episode", array(string)),
    url: json |> field("url", string),
    created: json |> field("created", string),
  };

let decodeInfo = json => {
  Json.Decode.{
    count: json |> field("count", int),
    pages: json |> field("pages", int),
    next: json |> field("next", string),
    prev: json |> field("prev", optional(string)),
  };
};

let decodeCharactersResultsObject = json => {
  Json.Decode.{
    info: json |> field("info", decodeInfo),
    results: json |> field("results", array(decodeCharacter)),
  };
};

// type joke = {
//   joke: string,
//   status: int,
//   count: int,
// };

// type message = {message: joke};

// type state = {
//   data: joke,
//   loading: bool,
// };

// type action =
//   | Loaded(joke)
//   | Loading;

// let initialState = {
//   data: {
//     joke: "My dog used to chase people on a bike a lot. It got so bad I had to take his bike away.",
//     status: 200,
//     count: 0,
//   },
//   loading: false,
// };

// let decodeJoke = (json): joke => {
//   Json.Decode.{
//     joke: json |> field("joke", string),
//     status: json |> field("status", int),
//     count: json |> field("count", int),
//   };
// };

// let decodeMessage = (json): message =>
//   Json.Decode.{message: json |> field("message", decodeJoke)};

// let fetchJoke = (callback, currentCount) => {
//   let payload = Js.Dict.empty();
//   Js.Dict.set(payload, "count", Json.Encode.int(currentCount));
//   Js.Promise.(
//     Fetch.fetchWithInit(
//       "/api/joke",
//       Fetch.RequestInit.make(
//         ~method_=Post,
//         ~body=
//           Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
//         ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
//         (),
//       ),
//     )
//     |> then_(Fetch.Response.json)
//     |> then_(json => {
//          //  Js.log2("Message Json", json);
//          let data = decodeMessage(json);
//          callback(data.message);
//          resolve();
//        })
//     |> catch(err => {
//          let data = {joke: "", status: 0, count: currentCount};
//          Js.log2("Error", err);
//          callback(data);
//          resolve();
//        })
//     |> ignore
//   );
// };

type json_body = {
  message: string,
  status: string,
};

let getInitialData = () => {
  Js.Promise.(
    Fetch.fetch("https://rickandmortyapi.com/api/character")
    |> then_(Fetch.Response.json)
    |> then_(json => {
         //  let data = decodeCharacter(json);
         Js.log2("Loader\n", json);
         resolve(json);
       })
    |> catch(err => {
         //  let data = {message: "", status: "error"};
         Js.log2("Error\n", err);
         // let body = Json.Encode.(
         //       object_([("message", string(err)), ("status", string("error"))])
         //     );
         let body =
           Obj.magic({
             message: "Error fetching characters.",
             status: "error",
           });
         resolve(body);
       })
  );
};

[@react.component]
let default = () => {
  let data =
    getInitialData()
    |> Js.Promise.then_(json => {
         Js.log2("Component\n", json);
         let data = decodeCharactersResultsObject(json);
         Js.Promise.resolve(data);
       });

  let createDiv = d => {
    <div> {React.string(d.name)} </div>;
  };

  <div>
    {data
     |> Js.Promise.then_(d => {
          let elements = Js.Array.map(createDiv, d.results);
          Js.Promise.resolve(<div> {React.array(elements)} </div>);
        })}
  </div>;
};
