open State;

open DataTypes;

open Page;

type action =
  | FetchArticles
  | ArticlesFetched(articlesObject)
  | ArticlesFailedToFetch(Js.Promise.error)
  | PathChanged(page);

let component = ReasonReact.reducerComponent("App");

let initialPage = () =>
  switch (ReasonReact.Router.dangerouslyGetInitialUrl().hash) {
  | "/home" => Home
  | "/newPost" => NewPost
  | "/settings" => Settings
  | "/signUp" => SignUp
  | _ => Home
  };

let make = _children => {
  ...component,
  didMount: self => {
    self.send(FetchArticles);
    ReasonReact.Router.push(
      switch (self.state.currentPage) {
      | Home => "#/home"
      | NewPost => "#/newPost"
      | Settings => "#/settings"
      | SignUp => "#/signUp"
      | _ => "#/home"
      },
    );
    ReasonReact.NoUpdate;
  },
  initialState: () => {
    currentPage: initialPage(),
    user: NotLoggedIn,
    articleList: Loading,
  },
  reducer: (action, state) =>
    switch (action) {
    | FetchArticles =>
      ReasonReact.UpdateWithSideEffects(
        {...state, articleList: Loading},
        (
          self =>
            Js.Promise.(
              Fetch.fetch(
                "https://conduit.productionready.io/api/articles?limit=10",
              )
              |> then_(Fetch.Response.json)
              |> then_(json =>
                   json
                   |> Decode.articlesObject
                   |> (
                     articlesObject =>
                       self.send(ArticlesFetched(articlesObject))
                   )
                   |> resolve
                 )
              |> catch(err =>
                   Js.Promise.resolve(self.send(ArticlesFailedToFetch(err)))
                 )
              |> ignore
            )
        ),
      )
    | ArticlesFetched(articlesObject) =>
      ReasonReact.Update({...state, articleList: Loaded(articlesObject)})
    | ArticlesFailedToFetch(error) =>
      ReasonReact.Update({...state, articleList: Error(error)})
    | PathChanged(page) => ReasonReact.Update({...state, currentPage: page})
    },
  render: self =>
    ReasonReact.arrayToElement([|
      <Header key="header" currentPage=self.state.currentPage />,
      <MainContent key="main-content" state=self.state />,
    |]),
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          switch (url.hash) {
          | "/home" => self.send(PathChanged(Home))
          | "/newPost" => self.send(PathChanged(NewPost))
          | "/settings" => self.send(PathChanged(Settings))
          | "/signUp" => self.send(PathChanged(SignUp))
          | _ => self.send(PathChanged(Unknown))
          }
        ),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
};
