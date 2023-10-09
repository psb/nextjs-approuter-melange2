type errorObject;
type nextError;
[@mel.get] external nextError: errorObject => nextError = "Error";
[@mel.get] external message: nextError => string = "message";
[@mel.get] external digest: nextError => string = "digest";
