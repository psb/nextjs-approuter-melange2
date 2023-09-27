open Bindings;

[@react.component]
let default = () => {
  <main
    className="flex min-h-screen flex-col items-center justify-between p-24">
    <div
      className="z-10 w-full max-w-5xl items-center justify-between font-mono text-sm lg:flex">
      <p
        className="fixed left-0 top-0 flex w-full justify-center border-b border-gray-300 bg-gradient-to-b from-zinc-200 pb-6 pt-8 backdrop-blur-2xl dark:border-neutral-800 dark:bg-zinc-800/30 dark:from-inherit lg:static lg:w-auto  lg:rounded-xl lg:border lg:bg-gray-200 lg:p-4 lg:dark:bg-zinc-800/30">
        {React.string("Get started by editing")}
        <code className="font-mono font-bold ml-2">
          {React.string("src/app/page.tsx")}
        </code>
      </p>
      <div
        className="fixed bottom-0 left-0 flex h-48 w-full items-end justify-center bg-gradient-to-t from-white via-white dark:from-black dark:via-black lg:static lg:h-auto lg:w-auto lg:bg-none">
        <a
          className="pointer-events-none flex place-items-center gap-2 p-8 lg:pointer-events-auto lg:p-0"
          href="https://vercel.com?utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
          target="_blank"
          rel="noopener noreferrer">
          {React.string("By")}
          <Image
            src="/vercel.svg"
            alt="Vercel Logo"
            className="dark:invert"
            width=100
            height=24
            priority=true
          />
        </a>
      </div>
    </div>
    <div
      className="relative flex place-items-center before:absolute before:h-[300px] before:w-[480px] before:-translate-x-1/2 before:rounded-full before:bg-gradient-radial before:from-white before:to-transparent before:blur-2xl before:content-[''] after:absolute after:-z-20 after:h-[180px] after:w-[240px] after:translate-x-1/3 after:bg-gradient-conic after:from-sky-200 after:via-blue-200 after:blur-2xl after:content-[''] before:dark:bg-gradient-to-br before:dark:from-transparent before:dark:to-blue-700 before:dark:opacity-10 after:dark:from-sky-900 after:dark:via-[#0141ff] after:dark:opacity-40 before:lg:h-[360px] z-[-1]">
      <Image
        className="relative dark:drop-shadow-[0_0_0.3rem_#ffffff70] dark:invert"
        src="/next.svg"
        alt="Next.js Logo"
        width=180
        height=37
        priority=true
      />
    </div>
    <div
      className="mb-32 grid text-center lg:mb-0 lg:grid-cols-4 lg:text-left">
      <a
        href="https://nextjs.org/docs?utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30"
        target="_blank"
        rel="noopener noreferrer">
        <h2 className="mb-3 text-2xl font-semibold">
          {React.string("Docs")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string(
             "Find in-depth information about Next.js features and API.",
           )}
        </p>
      </a>
      <a
        href="https://nextjs.org/learn?utm_source=create-next-app&utm_medium=appdir-template-tw&utm_campaign=create-next-app"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30"
        target="_blank"
        rel="noopener noreferrer">
        <h2 className="mb-3 text-2xl font-semibold">
          {React.string("Learn")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string(
             "Learn about Next.js in an interactive course with quizzes!",
           )}
        </p>
      </a>
      <a
        href="https://vercel.com/templates?framework=next.js&utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30"
        target="_blank"
        rel="noopener noreferrer">
        <h2 className="mb-3 text-2xl font-semibold">
          {React.string("Templates")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string("Explore the Next.js 13 playground.")}
        </p>
      </a>
      <a
        href="https://vercel.com/new?utm_source=create-next-app&utm_medium=appdir-template&utm_campaign=create-next-app"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30"
        target="_blank"
        rel="noopener noreferrer">
        <h2 className="mb-3 text-2xl font-semibold">
          {React.string("Deploy")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string(
             "Instantly deploy your Next.js site to a shareable URL with Vercel.",
           )}
        </p>
      </a>
      <Link
        href="/dogs"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30">
        <h2 className="flex mb-3 text-2xl font-semibold">
          <img
            src="/icon_50.png"
            width="30"
            className="mr-1"
            alt="Reason Logo"
          />
          {React.string("Dogs")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string("View a dog picture")}
        </p>
      </Link>
      <Link
        href="/jokes"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30">
        <h2 className="flex mb-3 text-2xl font-semibold">
          <img
            src="/icon_50.png"
            width="30"
            className="mr-1"
            alt="Reason Logo"
          />
          {React.string("Jokes")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string("Read a joke")}
        </p>
      </Link>
      <Link
        href="/rick-and-morty"
        className="group rounded-lg border border-transparent px-5 py-4 transition-colors hover:border-gray-300 hover:bg-gray-100 hover:dark:border-neutral-700 hover:dark:bg-neutral-800/30">
        <h2 className="flex mb-3 text-2xl font-semibold">
          <img
            src="/icon_50.png"
            width="30"
            className="mr-1"
            alt="Reason Logo"
          />
          {React.string("Rick & Morty")}
          <span
            className="inline-block ml-2 transition-transform group-hover:translate-x-1 motion-reduce:transform-none">
            {React.string({j|\u2192|j})}
          </span>
        </h2>
        <p className="m-0 max-w-[30ch] text-sm opacity-50">
          {React.string("Rick & Morty characters")}
        </p>
      </Link>
    </div>
  </main>;
};
