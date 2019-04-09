#shader vertex
#version 320 es

layout(location = 0) in vec4 position;

void main(){
	gl_Position = position;
};

#shader fragment
#version 320 es
precision mediump float;

layout(location = 0) out vec4 color;

void main(){
	color = vec4(0.2f, 0.3f, 0.8f, 1.0f);
};