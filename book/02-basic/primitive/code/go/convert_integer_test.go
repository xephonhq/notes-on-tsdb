package primitive

import "testing"

func TestConvertInteger(t *testing.T) {
	var c int8 = -128
	var uc = uint8(c)
	t.Logf("%d %d", c, uc)
}
