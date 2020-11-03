type trigger = [ | `get | `set];

type atomEffect('value) = {
  node: Recoil__Value.readWrite('value),
  trigger,
  setSelf: ('value => 'value) => unit,
  resetSelf: unit => unit,
  onSet: (~newValue: 'value, ~oldValue: 'value) => unit,
};

type atomConfig('value) = {
  key: string,
  default: 'value,
};

type atomWithEffectsConfig('value) = {
  key: string,
  default: 'value,
  effects_UNSTABLE: array(atomEffect('value) => option(unit => unit)),
};

type atomFamilyConfig('parameter, 'value) = {
  key: string,
  default: 'parameter => 'value,
};

type atomFamilyWithEffectsConfig('parameter, 'value) = {
  key: string,
  default: 'parameter => 'value,
  effects_UNSTABLE:
    'parameter => array(atomEffect('value) => option(unit => unit)),
};

type atomFamily('parameter, 'value) = 'parameter => 'value;

[@bs.module "recoil"]
external atom: atomConfig('value) => Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external atomWithEffects:
  atomWithEffectsConfig('value) => Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external asyncAtom:
  atomConfig(Js.Promise.t('value)) => Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external asyncAtomWithEffects:
  atomWithEffectsConfig('value) => Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external atomFromRecoilValue:
  atomConfig(Recoil__Value.t('value, _)) => Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external atomWithEffectsFromRecoilValue:
  atomWithEffectsConfig(Recoil__Value.t('value, _)) =>
  Recoil__Value.readWrite('value) =
  "atom";

[@bs.module "recoil"]
external atomFamily:
  atomFamilyConfig('parameter, 'value) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";

[@bs.module "recoil"]
external asyncAtomFamily:
  atomFamilyConfig('parameter, Js.Promise.t('value)) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";

[@bs.module "recoil"]
external atomFamilyFromRecoilValue:
  atomFamilyConfig('parameter, Recoil__Value.t('value, _)) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";

[@bs.module "recoil"]
external atomFamilyWithEffects:
  atomFamilyWithEffectsConfig('parameter, 'value) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";

[@bs.module "recoil"]
external asyncAtomFamilyWithEffects:
  atomFamilyWithEffectsConfig('parameter, Js.Promise.t('value)) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";

[@bs.module "recoil"]
external atomFamilyWithEffectsFromRecoilValue:
  atomFamilyWithEffectsConfig('parameter, Recoil__Value.t('value, _)) =>
  atomFamily('parameter, Recoil__Value.readWrite('value)) =
  "atomFamily";
