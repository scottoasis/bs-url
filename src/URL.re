type t;

[@bs.module "url"] [@bs.new] external make: string => t = "URL";
[@bs.module "url"] [@bs.new]
external makeWithBase: (string, string) => t = "URL";

/* Members */
[@bs.get] external hash: t => string = "";
[@bs.get] external host: t => string = "";
[@bs.get] external hostname: t => string = "";
[@bs.get] external href: t => string = "";
[@bs.get] external origin: t => string = "";
[@bs.get] external password: t => string = "";
[@bs.get] external pathname: t => string = "";
[@bs.get] external port: t => string = "";
[@bs.get] external protocol: t => string = "";
[@bs.get] external search: t => string = "";
[@bs.get] external searchParams: t => URLSearchParams.t = "";
[@bs.get] external username: t => string = "";

[@bs.set] external set_username: (t, string) => unit = "username";
let withUsername = (username, this) => {
  this->set_username(username);
  this;
};

[@bs.set] external set_password: (t, string) => unit = "password";
let withPassword = (password, this) => {
  this->set_password(password);
  this;
};

[@bs.set] external set_hash: (t, string) => unit = "hash";
let withHash = (hash, this) => {
  this->set_hash(hash);
  this;
};

[@bs.set] external set_port: (t, string) => unit = "port";
let withPort = (port, this) => {
  this->set_port(port);
  this;
};

[@bs.set] external set_protocol: (t, string) => unit = "protocol";
let withProtocol = (protocol, this) => {
  this->set_protocol(protocol);
  this;
};

[@bs.set] external set_searchParams: (t, string) => unit = "searchParams";
let withSearchParams = (searchParams, this) => {
  this->set_searchParams(searchParams);
  this;
};

/* Instance Methods */
[@bs.send] external toString: t => string = "";
[@bs.send] external toJSON: t => string = "";

/* Static methods */
[@bs.module "url"] [@bs.val] external domainToASCII: string => string = "";
[@bs.module "url"] [@bs.val] external domainToUnicode: string => string = "";
[@bs.module "url"] [@bs.val]
external formatInternal:
  (
    t,
    {
      .
      "auth": bool,
      "fragment": bool,
      "search": bool,
      "unicode": bool,
    }
  ) =>
  string =
  "format";

let unwrapOptWithDefault = (optionalValue, default) =>
  switch (optionalValue) {
  | Some(v) => v
  | None => default
  };

let format = (~auth=?, ~fragment=?, ~search=?, ~unicode=?, t) =>
  formatInternal(
    t,
    {
      "auth": unwrapOptWithDefault(auth, true),
      "fragment": unwrapOptWithDefault(fragment, true),
      "search": unwrapOptWithDefault(search, true),
      "unicode": unwrapOptWithDefault(unicode, false),
    },
  );
[@bs.module "url"] [@bs.val] external parse: string => t = "";
[@bs.module "url"] [@bs.val] external resolve: (string, string) => t = "";
