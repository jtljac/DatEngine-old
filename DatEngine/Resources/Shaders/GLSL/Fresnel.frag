float fresnel(vec3 CameraPosition, vec3 WorldPosition, vec3 WorldNormal, float exponent){
	float fresnel = dot(WorldNormal, normalize(CameraPosition - WorldPosition));
    fresnel = 1.0 - fresnel;
    return pow(fresnel, abs(exponent));
}