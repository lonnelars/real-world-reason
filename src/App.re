include Page;

type state = {currentPage: page};

type action =
  | PathChanged(page);

let component = ReasonReact.reducerComponent("App");

let initialPage = () =>
  switch (ReasonReact.Router.dangerouslyGetInitialUrl().hash) {
  | "home" => Home
  | "newPost" => NewPost
  | "settings" => Settings
  | "signUp" => SignUp
  | _ => Home
  };

let make = _children => {
  ...component,
  initialState: () => {currentPage: initialPage()},
  reducer: (action, _state) =>
    switch (action) {
    | PathChanged(page) => ReasonReact.Update({currentPage: page})
    },
  render: self =>
    ReasonReact.arrayToElement([|
      <Header currentPage=self.state.currentPage />,
      <MainContent page=self.state.currentPage />,
    |]),
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          switch (url.hash) {
          | "home" => self.send(PathChanged(Home))
          | "newPost" => self.send(PathChanged(NewPost))
          | "settings" => self.send(PathChanged(Settings))
          | "signUp" => self.send(PathChanged(SignUp))
          | _ => self.send(PathChanged(Unknown))
          }
        ),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
};