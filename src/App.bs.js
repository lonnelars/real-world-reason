// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var Header$ReactTemplate = require("./Header.bs.js");

var component = ReasonReact.statelessComponent("App");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return ReasonReact.element(/* None */0, /* None */0, Header$ReactTemplate.make(/* array */[]));
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
