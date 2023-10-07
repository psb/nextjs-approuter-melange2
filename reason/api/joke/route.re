open Bindings.Server;

type joke_count = {count: int};

type joke_result = {
  joke: string,
  _id: string,
  status: int,
};

let decodeJokeCount = (json): joke_count => {
  Json.Decode.{count: json |> field("count", int)};
};

let decodeJoke = (json): joke_result =>
  Json.Decode.{
    joke: json |> field("joke", string),
    status: json |> field("status", int),
    _id: json |> field("id", string),
  };

[@mel.as POST]
let handler = request => {
  let jokeCount =
    request_json(request)
    |> Js.Promise.then_(json => {
         //  Js.log2("request_json", json);
         let jc = decodeJokeCount(json);
         Js.Promise.resolve(jc);
       })
    |> Js.Promise.catch(err => {
         Js.log2("Joke Count post error: ", err);
         Js.Promise.resolve({count: 0});
       });

  Js.Promise.(
    Fetch.fetchWithInit(
      "https://icanhazdadjoke.com/",
      Fetch.RequestInit.make(
        ~method_=Get,
        ~headers=
          Fetch.HeadersInit.make({
            "Accept": "application/json",
            "User-Agent": "nextjs-approuter-reason (https://github.com/psb/nextjs-approuter-reason)",
          }),
        (),
      ),
    )
    |> then_(Fetch.Response.json)
    |> then_(json => {
         //  Js.log2("json", json);
         let data = decodeJoke(json);
         jokeCount
         |> Js.Promise.then_(jc => {
              let body =
                Obj.magic({
                  "joke": data.joke,
                  "count": jc.count + 1,
                  "status": data.status,
                });

              resolve(
                response_json(response, {message: body}, {status: 200}),
              );
            });
       })
    |> catch(err => {
         Js.log2("server Error Json", err);
         jokeCount
         |> Js.Promise.then_(jc => {
              let body =
                Obj.magic({"joke": err, "count": jc.count, "status": 500});

              resolve(
                response_json(response, {message: body}, {status: 500}),
              );
            });
       })
  );
};
