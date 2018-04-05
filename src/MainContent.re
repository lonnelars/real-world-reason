open State;

let component = ReasonReact.statelessComponent("MainContent");

let make = (~state: state, _children) => {
  ...component,
  render: _self =>
    <div>
      (
        switch (state.currentPage) {
        | Home => <Home state />
        | NewPost => ReasonReact.stringToElement("new post")
        | Settings => ReasonReact.stringToElement("settings")
        | SignUp => ReasonReact.stringToElement("sign up")
        | Unknown => ReasonReact.stringToElement("unknown path")
        }
      )
    </div>,
};
