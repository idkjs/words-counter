// Generated by BUCKLESCRIPT VERSION 5.0.3, PLEASE EDIT WITH CARE

import * as React from "react";

((require('./Button.css')));

function classNameOfCategory(category) {
  return "Button " + (
          category ? "primary" : "secondary"
        );
}

function Button(Props) {
  var match = Props.onClick;
  var onClick = match !== undefined ? match : (function (param) {
        return /* () */0;
      });
  var title = Props.title;
  var children = Props.children;
  var match$1 = Props.disabled;
  var disabled = match$1 !== undefined ? match$1 : false;
  var match$2 = Props.category;
  var category = match$2 !== undefined ? match$2 : /* SECONDARY */0;
  return React.createElement("button", {
              className: classNameOfCategory(category),
              title: title,
              disabled: disabled,
              onClick: onClick
            }, children);
}

var make = Button;

export {
  classNameOfCategory ,
  make ,
  
}
/*  Not a pure module */
