[@mel.module "next/image"] [@react.component]
external make:
  (
    ~className: string,
    ~src: string,
    ~alt: string,
    ~width: int,
    ~height: int,
    ~priority: bool
  ) =>
  React.element =
  "default";
