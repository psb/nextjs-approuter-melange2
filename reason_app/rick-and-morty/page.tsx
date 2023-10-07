// @ts-ignore
import PageComponent from "./PageComponent";

async function getData() {
  const res = await fetch("https://rickandmortyapi.com/api/character");

  if (!res.ok) {
    throw new Error("Failed to fetch data");
  }

  return res.json();
}

export default async function Page() {
  const data = await getData();

  return <PageComponent json={data}></PageComponent>;
}
