[@mel.config {flags: [|"--preamble", "\"use client\";"|]}];

type params = {id: string};

type origin = {
  name: string,
  url: string,
};
type location = {
  name: string,
  url: string,
};

type character = {
  id: int, // The id of the character.
  name: string, // The name of the character.
  status: string, // The status of the character ('Alive', 'Dead' or 'unknown').
  species: string, // The species of the character.
  type_of_character: string, // The type or subspecies of the character.
  gender: string, // The gender of the character ('Female', 'Male', 'Genderless' or 'unknown').
  origin, // Name and link to the character's origin location.
  location, // Name and link to the character's last known location endpoint.
  image: string, // Link to the character's image. All images are 300x300px and most are medium shots or portraits since they are intended to be used as avatars.
  episode: array(string), // List of episodes in which this character appeared.
  url: string, // Link to the character's own URL endpoint.
  created: string // Time at which the character was created in the database.
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

[@react.component]
let default = (~params: params) => {
  let (character, setCharacter) = React.useState(_ => None);

  React.useEffect0(() => {
    Bindings.Server.(
      fetch("https://rickandmortyapi.com/api/character/" ++ params.id)
      ->Promise.flatMap(res => json(res))
      ->Promise.map(json => decodeCharacter(json))
      ->Promise.get(ch => setCharacter(_ => Some(ch)))
    );
    None;
  });

  let characterComponent = c => {
    <div>
      <h3> {React.string(c.name)} </h3>
      <Bindings.Image
        src={c.image}
        width=500
        height=500
        alt={c.name}
        placeholder="blur"
        blurDataURL="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mNk+P+/HgAFhAJ/wlseKgAAAABJRU5ErkJggg=="
      />
      <p> {React.string("Status: " ++ c.status)} </p>
    </div>;
  };

  <div className="ml-4">
    <div>
      {switch (character) {
       | Some(c) => characterComponent(c)
       | None => React.string("Loading")
       //  | _ => raise(Not_found) // For testing ErrorBoundary
       }}
    </div>
    <Bindings.Link href="/rick-and-morty" className="underline">
      {React.string("back")}
    </Bindings.Link>
  </div>;
};
