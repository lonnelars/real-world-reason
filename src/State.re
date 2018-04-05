open DataTypes;

open Page;

type articleList =
  | Loading
  | Loaded(articlesObject)
  | Error(Js.Promise.error);

type logInStatus =
  | NotLoggedIn
  | LoggedIn(user);

type state = {
  currentPage: page,
  user: logInStatus,
  articleList,
};
