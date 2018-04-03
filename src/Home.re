let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="home-page">
      <div className="banner">
        <div className="container">
          <h1 className="logo-font"> (text("conduit")) </h1>
          <p> (text("A place to share your knowledge.")) </p>
        </div>
      </div>
    </div>,
};