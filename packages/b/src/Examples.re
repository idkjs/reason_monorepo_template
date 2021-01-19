let render = makeContainer => {
  open A;
  // All 4 examples.
  ReactDOMRe.render(
    <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>,
    makeContainer("Blinking Greeting"),
  );

  ReactDOMRe.render(<ReducerFromReactJSDocs />, makeContainer("Reducer From ReactJS Docs"));

  ReactDOMRe.render(<FetchedDogPictures />, makeContainer("Fetched Dog Pictures"));

  ReactDOMRe.render(<ReasonUsingJSUsingReason />, makeContainer("Reason Using JS Using Reason"));
};
