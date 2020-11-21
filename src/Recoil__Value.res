type readOnlyMode = ReadOnly
type readWriteMode = ReadWrite

type t<'value, 'mode>
type readOnly<'value> = t<'value, readOnlyMode>
type readWrite<'value> = t<'value, readWriteMode>

@bs.module("recoil") external isRecoilValue: 'a => bool = "isRecoilValue"
