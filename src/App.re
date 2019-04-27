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

[@react.component]
let make = () => {
  // useState requires a function.
  let (text, setText) = React.useState(() => "");
  // let (count, setCount) = React.useState(()=> int);
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;
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
  </div>;
};