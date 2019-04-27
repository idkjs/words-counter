[%bs.raw {|require('./Button.css')|}];

type categoryT =
  | SECONDARY
  | PRIMARY;

let classNameOfCategory = category =>
  "Button "
  ++ (
    switch (category) {
    | SECONDARY => "secondary"
    | PRIMARY => "primary"
    }
  );

[@react.component]
let make =
    (
      ~onClick= _ => (), // this has type option(ReactEvent.Mouse.t => unit) which we can overide by passing an onClick value to it, otherwise it calls click by default
      ~title: string,
      ~children: ReasonReact.reactElement,
      ~disabled=false,
      ~category=SECONDARY,
    ) => {
  <button onClick className={category |> classNameOfCategory} title disabled>
    children
  </button>;
};