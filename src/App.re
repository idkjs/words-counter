[%bs.raw {|require('./App.css')|}];

[@react.component]
let make = () => {
  // useState requires a function.
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;

  <div className="App">
    <div className="Header"> <h3> {"Word Counter" |> React.string} </h3> </div>
    <textarea
      placeholder="Express yourself"
      value=text
      onChange=handleTextChange
    />
  </div>;
};