[@mel.config {flags: [|"--preamble", "\"use client\";"|]}];

type reset = unit => unit;

[@react.component]
let default = (~error: Bindings.Error.errorObject, ~reset: reset) => {
  React.useEffect1(
    () => {
      Js.log2("Error: ", error);
      None;
    },
    [|error|],
  );

  <div>
    <h2> {React.string("Something went wrong!")} </h2>
    // Attempt to recover by trying to re-render the segment
    <button className="p-2 mt-2 bg-blue-800" onClick={_ => reset()}>
      {React.string("Try again")}
    </button>
  </div>;
};
