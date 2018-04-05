include Page;

let component = ReasonReact.statelessComponent("Header");

let text = ReasonReact.stringToElement;

let navLinkClassList = (page, linkToPage) =>
  "nav-link "
  ++ (
    if (page == linkToPage) {
      "active";
    } else {
      "";
    }
  );

let make = (~currentPage, _children) => {
  ...component,
  render: _self =>
    <nav className="navbar navbar-light">
      <div className="container">
        <a className="navbar-brand" href="index.html"> (text("conduit")) </a>
        <ul className="nav navbar-nav pull-xs-right">
          <li className="nav-item">
            <a className=(navLinkClassList(currentPage, Home)) href="#/home">
              (text("Home"))
            </a>
          </li>
          <li className="nav-item">
            <a
              className=(navLinkClassList(currentPage, NewPost))
              href="#/newPost">
              <i className="ion-compose" />
              (text("New post"))
            </a>
          </li>
          <li className="nav-item">
            <a
              className=(navLinkClassList(currentPage, Settings))
              href="#/settings">
              <i className="ion-gear-a" />
              (text("Settings"))
            </a>
          </li>
          <li className="nav-item">
            <a
              className=(navLinkClassList(currentPage, SignUp))
              href="#/signUp">
              (text("Sign up"))
            </a>
          </li>
        </ul>
      </div>
    </nav>,
};
