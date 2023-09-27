type metadata = {
  title: string,
  description: string,
};
let metadata: metadata;

// let getInitialData: unit => Js.Promise.t(Js.Json.t)

[@react.component]
let default: unit => React.element;
