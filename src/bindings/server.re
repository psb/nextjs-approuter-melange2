type request;
external request: request = "request";
[@mel.send]
external request_json: request => Js.Promise.t(Js.Json.t) = "json";
type t;
type message = {message: string};
type status = {status: int};
type response;
[@mel.module "next/server"] external response: response = "NextResponse";
[@mel.send] external response_json: (response, message, status) => t = "json";
