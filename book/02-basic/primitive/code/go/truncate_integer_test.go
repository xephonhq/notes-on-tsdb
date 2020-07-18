package primitive

import "testing"

func TestTruncateInteger(t *testing.T) {
	var sa1 int16 = 256
	var ca1 = int8(sa1)
	t.Logf("%d %d", sa1, ca1) // 256 0
	var sa2 int16 = 255
	var ca2 = int8(sa2)
	t.Logf("%d %d", sa2, ca2) // 255 -1
}
