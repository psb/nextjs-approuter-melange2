# NextJS App Router, Reason and Melange 2

This is a basic project that shows you how you can mix [Next.js](https://nextjs.org/) with [Reason](https://reasonml.github.io/en), [Reason React](https://reasonml.github.io/reason-react/en), and [Vercel](https://vercel.com/) serverless functions. The project uses [Melange 2](https://melange.re/v2.0.0/) to transform the Reason code to JS.

[See this blog post for more information](https://dev.to/psb/reason-and-react-meta-frameworks-d7n)

This project is deployed at: https://nextjs-approuter-melange2.vercel.app/

## Project Structure

```sh
/
├── _build/
├── public/
├── reason_app/
├── reason_bindings/
├── src/
│   ├── app/
│   ├── node_modules/
│   └── reason_bindings/
├── package.json
├── next.config.js
├── <project_name>.opam
├── dune
├── dune-project
└── Makefile
```

### App layout

The main Reason and ReasonReact code is in the `reason_app` folder, which is equivalent to `src/app` in a NextJS project. Reason bindings to NextJS components are in the `reason_bindings` folder.

To create the NextJS App Router folder layout the Reason code is built/compiled to the `_build` directory and then promoted (i.e., copied) back out into the root directory. See the dune files for more information.

Once the output JS is promoted then the NextJS dev tooling takes over and serves the app.

### Other Files

`dune` files tell Dune how to load BuckleScript libraries installed from npm, where and how to emit JS code, and to define libraries. View the files for the details.

The `<project_name>.opam` file contains the Reason/OCaml packages required and `package.json` contains the JS packages required.

The `dune-project` file describes the project.

The `Makefile` contains the commands for the project.

## Commands

Commands for developing and building the project are found in the Makefile. The setup is very similar to running commands found in a `package.json` file.

You can see all available commands by running `make help` or just `make`. Here
are a few of the most useful ones:

- `make init`: set up opam local switch and download Reason/OCaml, Melange and
  JavaScript dependencies
- `make install`: install Reason/OCaml, Melange and JavaScript dependencies
- `make watch`: watch for Reason/OCaml filesystem changes and have Melange rebuild on every change
- `make dev`: serve the JS application with a local HTTP server
- `make bundle`: creates production build of app

### Setup

After [getting up and running with OCaml](https://ocaml.org/docs/up-and-running), run:

```sh
make init
```

This will setup the project and install the packages.

### Development

```sh
# in one terminal run:
make watch

# in another terminal run:
make dev
```

## Deployment

The easiest way to deploy an app like this is using GitHub and connecting the repository to Vercel. For this to work properly the Melange `node_modules` folder (`src/node_modules`) must be committed to the repository.
