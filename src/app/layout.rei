type metadata = {
  title: string,
  description: string,
};
let metadata: metadata;

[@react.component]
let default: (~children: React.element) => React.element;
