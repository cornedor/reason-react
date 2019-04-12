[@bs.config {jsx: 3}];

[@react.component]
let make = (~a, ~b, _) => {
    Js.log("This function should be named `Test`");
    <div />
};


module Foo = {
    [@react.component]
    [@bs.module "Foo"]
    external component: (~a:int, ~b:string, _) => React.element = "";
};

// <Foo.component a=1 b="1" />;

module Bar = {
    [@react.component]
    let make = (~a, ~b, _) => {
        Js.log("This function should be named `Test$Bar`");
        <div />
    };
    [@react.component]
    let component = (~a, ~b, _) => {
        Js.log("This function should be named `Test$Bar$component`");
        <div />
    };
}

module type X_int = {
    let x: int;
};

module Func = (M: X_int) => {
    let x = M.x + 1;
    [@react.component]
    let make = React.forwardRef((~a, ~b, ref) => {
        Js.log("This function should be named `Test$Func`", M.x);
        <div ref />
    });
};



[@react.component]
let make = (~a=1, ~b=?, _) => {
    Js.log("This function should be named `Test`");
    <div />
};


[@react.component]
[@bs.module "Foo"]
external component: (~a:int=?, ~b:string, ~c:Js.Nullable.t(Js.t(foo))=?, _) => React.element = ""; 


[@react.component]
let make = (~a=1, ~b=?, _) => {
    <div />
};

module Issue369Optionals = {
  module One = {
    [@react.component]
    let make = (~prop: string="") => React.null;
  };

  module Two = {
    [@react.component]
    let make = (~prop: option(string)="") => React.null;
  };

  module All = {
    [@react.component]
    let make = (
      ~labelled,
      ~labelledT: string,
      ~optional=?,
      ~optionalT: option(string)=?,
      ~default="",
      ~defaultT: string="",
    ) => React.null;
  };

  let one = <One prop="foo" />;
  let two = <Two prop=Some("foo") />;
};
