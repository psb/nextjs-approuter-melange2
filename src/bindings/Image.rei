[@react.component]
let make:
  (
    ~className: string=?,
    ~src: string,
    ~alt: string,
    ~width: int,
    ~height: int,
    ~priority: bool=?,
    ~placeholder: string=?,
    ~blurDataURL: string=?
  ) =>
  React.element;
