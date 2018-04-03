let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="home-page">
      (ReasonReact.stringToElement("home route"))
    </div>,
};