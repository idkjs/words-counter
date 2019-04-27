[%bs.raw {|require('./App.css')|}];

let countWordsInString = text => {
  let spacesRegex = Js.Re.fromString("\s+");

  switch (text) {
  | "" => 0
  | noneEmptyText =>
    noneEmptyText
    |> Js.String.trim
    |> Js.String.splitByRe(spacesRegex)
    |> Js.Array.length
  };
};
module Times = {
  [@bs.module "./times.svg"] [@react.component]
  external make: (~height: string) => React.element = "default";
};

[@react.component]
let make = () => {
  // useState requires a function.
  let (text, setText) = React.useState(() => "");
  // let (count, setCount) = React.useState(()=> int);
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;
  let handleClearClick = _ => setText(_=>"");
  let wordsCountText =
    (text |> countWordsInString |> string_of_int) ++ " words";
    // Js.log(wordsCountText);
  <div className="App">
    <div className="Header"> <h3> {"Word Counter" |> React.string} </h3>
          <span> {ReasonReact.string(wordsCountText)} </span>
     </div>
    <textarea
      placeholder="Express yourself"
      value=text
      onChange=handleTextChange
    />
    <div className="footer">
      <Button
        title="Clear text"
        onClick=handleClearClick
        disabled={String.length(text) === 0}>
        <Times height="20px" />
      </Button>
    </div>
    // <Component1 message="HEY"/>
    // <Component2 greeting="HEY"/>
  </div>;
};