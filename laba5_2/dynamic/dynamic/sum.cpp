extern "C" __declspec(dllexport) bool Func(double arr)
{
	if (arr > 0) { return true; }
	else { return false; }
}