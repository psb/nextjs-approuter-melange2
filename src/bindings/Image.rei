[@react.component]
let make:
  (
    ~className: string,
    ~src: string,
    ~alt: string,
    ~width: int,
    ~height: int,
    ~priority: bool
  ) =>
  React.element;
