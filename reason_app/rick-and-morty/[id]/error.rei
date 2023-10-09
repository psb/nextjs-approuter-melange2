type reset;
[@react.component]
let default:
  (~error: Bindings.Error.errorObject, ~reset: reset) => React.element;
