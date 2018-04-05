type user = {
  username: string,
  bio: option(string),
  image: string,
  following: bool,
};

type article = {
  slug: string,
  title: string,
  description: string,
  body: string,
  tagList: array(string),
  createdAt: string,
  updatedAt: string,
  favorited: bool,
  favoritesCount: int,
  author: user,
};

type articlesObject = {
  articles: array(article),
  articlesCount: int,
};

module Decode = {
  let user = json =>
    Json.Decode.{
      username: json |> field("username", string),
      bio: json |> optional(field("bio", string)),
      image: json |> field("image", string),
      following: json |> field("following", bool),
    };
  let article = json =>
    Json.Decode.{
      slug: json |> field("slug", string),
      title: json |> field("title", string),
      description: json |> field("description", string),
      body: json |> field("body", string),
      tagList: json |> field("tagList", array(string)),
      createdAt: json |> field("createdAt", string),
      updatedAt: json |> field("updatedAt", string),
      favorited: json |> field("favorited", bool),
      favoritesCount: json |> field("favoritesCount", int),
      author: json |> field("author", user),
    };
  let articlesObject = json =>
    Json.Decode.{
      articles: json |> field("articles", array(article)),
      articlesCount: json |> field("articlesCount", int),
    };
};