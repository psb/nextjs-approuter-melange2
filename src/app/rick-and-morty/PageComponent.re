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

[@react.component]
let default = (~json) => {
  let createLi = c => {
    let stringOfId = Int.to_string(c.id);
    <Bindings.Link
      href={j| /rick-and-morty/$stringOfId |j} className="underline">
      <li className="p-4 hover:bg-slate-800 rounded-md" key=stringOfId>
        {React.string(c.name)}
      </li>
    </Bindings.Link>;
  };

  let charactersList = json => {
    // Js.log2("Default: ", json);
    let data = decodeCharactersResultsObject(json);
    let lis = Js.Array.map(createLi, data.results);

    <ul> {React.array(lis)} </ul>;
  };

  <div className="ml-4"> {charactersList(json)} </div>;
};
