include Page;

let component = ReasonReact.statelessComponent("MainContent");

let make = (~page, _children) => {
  ...component,
  render: _self =>
    <div>
      (
        ReasonReact.stringToElement(
          switch (page) {
          | Home => "home"
          | NewPost => "new post"
          | Settings => "settings"
          | SignUp => "sign up"
          | Unknown => "unknown path"
          },
        )
      )
    </div>,
};