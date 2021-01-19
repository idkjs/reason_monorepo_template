open Webapi.Dom;

// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.

let style = document |> Document.createElement("style");
let htmlDocument = Document.asHtmlDocument(document)->Belt.Option.getExn;

htmlDocument |> HtmlDocument.head |> Element.appendChild(style);

style->Element.setInnerHTML(ExampleStyles.style);

let makeContainer = text => {
  let container = document |> Document.createElement("div");
  container |> Element.setAttribute("class", "container");

  let title = document |> Document.createElement("div");
  title |> Element.setAttribute("class", "containerTitle");
  title->Element.setInnerText(text);

  let content = document |> Document.createElement("div");
  content |> Element.setAttribute("class", "containerContent");

  container |> Element.appendChild(title);
  container |> Element.appendChild(content);
  switch (htmlDocument->HtmlDocument.body) {
  | None => ()
  | Some(body) => body |> Element.appendChild(container)
  };

  content;
};

Redirect.render(makeContainer);
