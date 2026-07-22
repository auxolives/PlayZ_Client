class PlayZNoBuildZone
{
	string Name;
	float X;
	float Y;
	float Z;
	float Radius;

	void PlayZNoBuildZone()
	{
		Name = "";
		X = 0;
		Y = 0;
		Z = 0;
		Radius = 0;
	}

	void Set(string name, float x, float y, float z, float radius)
	{
		Name = name;
		X = x;
		Y = y;
		Z = z;
		Radius = radius;
	}

	//! Horizontal (XZ) cylinder — Y is documentation only.
	bool ContainsHorizontal(vector pos)
	{
		if (Radius <= 0)
			return false;

		vector center = Vector(X, 0, Z);
		vector flat = Vector(pos[0], 0, pos[2]);
		return vector.Distance(center, flat) <= Radius;
	}
}
