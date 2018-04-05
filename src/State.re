open DataTypes;

open Page;

type articleList =
  | Loading
  | Loaded(articlesObject)
  | Error(Js.Promise.error);

type state = {
  currentPage: page,
  articleList,
};