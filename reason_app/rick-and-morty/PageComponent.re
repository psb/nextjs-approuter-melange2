type metadata = {
  title: string,
  description: string,
};
let metadata = {
  title: "Rick & Morty Characters",
  description: "View Rick & Morty characters",
};

type character = {
  id: int, // The id of the character.
  name: string // The name of the character.
};

type info = {
  count: int,
  pages: int,
  next: string,
  prev: option(string),
};

type characters_object_data = {
  info,
  results: array(character),
};

let decodeCharacter = (json): character =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
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
    <li key=stringOfId className="p-4 hover:bg-slate-800 rounded-md">
      <Bindings.Link
        href={j| /rick-and-morty/$stringOfId |j} className="underline">
        {React.string(c.name)}
      </Bindings.Link>
    </li>;
  };

  let charactersList = json => {
    let data = decodeCharactersResultsObject(json);
    let lis = Js.Array.map(createLi, data.results);

    <ul> {React.array(lis)} </ul>;
  };

  <div className="ml-4">
    {charactersList(json)}
    <Bindings.Link href="/" className="underline">
      {React.string("back")}
    </Bindings.Link>
  </div>;
};
