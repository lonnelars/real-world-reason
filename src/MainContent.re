include Page;

let component = ReasonReact.statelessComponent("MainContent");

let make = (~page, _children) => {
  ...component,
  render: _self =>
    <div>
      (
        switch (page) {
        | Home => <Home />
        | NewPost => ReasonReact.stringToElement("new post")
        | Settings => ReasonReact.stringToElement("settings")
        | SignUp => ReasonReact.stringToElement("sign up")
        | Unknown => ReasonReact.stringToElement("unknown path")
        }
      )
    </div>,
};