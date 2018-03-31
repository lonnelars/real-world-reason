/* todo: add "active" class to element which page is active */
let component = ReasonReact.statelessComponent("Header");

let text = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <nav className="navbar navbar-light">
      <div className="container">
        <a className="navbar-brand" href="index.html"> (text("conduit")) </a>
        <ul className="nav navbar-nav pull-xs-right">
          <li className="nav-item">
            <a className="nav-link active" href=""> (text("Home")) </a>
          </li>
          <li className="nav-item">
            <a className="nav-link" href="">
              <i className="ion-compose" />
              (text("New post"))
            </a>
          </li>
          <li className="nav-item">
            <a className="nav-link" href="">
              <i className="ion-gear-a" />
              (text("Settings"))
            </a>
          </li>
          <li className="nav-item">
            <a className="nav-link" href=""> (text("Sign up")) </a>
          </li>
        </ul>
      </div>
    </nav>,
};