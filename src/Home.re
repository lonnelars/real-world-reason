open DataTypes;

let text = ReasonReact.stringToElement;

let articlePreview = article =>
  <div key=article.slug className="article-preview">
    <div className="article-meta">
      <a href="profile.html"> <img src="http://i.imgur.com/Qr71crq.jpg" /> </a>
      <div className="info">
        <a href="" className="author"> (article.author.username |> text) </a>
        <span className="date"> (article.createdAt |> text) </span>
      </div>
      <button className="btn btn-outline-primary btn-sm pull-xs-right">
        <i className="ion-heart" />
        (article.favoritesCount |> string_of_int |> text)
      </button>
    </div>
    <a href="" className="preview-link">
      <h1> (article.title |> text) </h1>
      <p> (article.description |> text) </p>
      <span> (text("Read more...")) </span>
    </a>
  </div>;

let component = ReasonReact.statelessComponent("Home");

let make = (~articles: State.articleList, _children) => {
  ...component,
  render: _self =>
    <div className="home-page">
      <div className="banner">
        <div className="container">
          <h1 className="logo-font"> (text("conduit")) </h1>
          <p> (text("A place to share your knowledge.")) </p>
        </div>
      </div>
      <div className="container page">
        <div className="row">
          <div className="col-md-9">
            <div className="feed-toggle">
              <ul className="nav nav-pills outline-active">
                <li key="your-feed" className="nav-item">
                  <a className="nav-link disabled" href="">
                    (text("Your Feed"))
                  </a>
                </li>
                <li key="global-feed" className="nav-item">
                  <a className="nav-link active" href="">
                    (text("Global Feed"))
                  </a>
                </li>
              </ul>
            </div>
            <ul>
              (
                switch (articles) {
                | Loading => <p> (text("Loading...")) </p>
                | Loaded(articlesObject) =>
                  Array.map(
                    article => articlePreview(article),
                    articlesObject.articles,
                  )
                  |> ReasonReact.arrayToElement
                | Error(error) =>
                  Js.log(error);
                  <p>
                    (
                      text(
                        "Could not load list of articles. See console for more details.",
                      )
                    )
                  </p>;
                }
              )
            </ul>
          </div>
          <div className="col-md-3">
            <div className="sidebar">
              <p> (text("Popular Tags")) </p>
              <div className="tag-list">
                <a href="" className="tag-pill tag-default">
                  (text("programming"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("javascript"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("emberjs"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("angularjs"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("react"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("mean"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("node"))
                </a>
                <a href="" className="tag-pill tag-default">
                  (text("rails"))
                </a>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>,
};