[@mel.module "next/link"] [@react.component]
external make:
  (~className: string, ~href: string, ~children: React.element) =>
  React.element =
  "default";
