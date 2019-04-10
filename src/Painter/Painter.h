class Painter {
	public:
		Painter();
		~Painter();

		// Add canvas as parameter when class was created
		void Draw();

		// Adds a motive that the artist will draw to the canvas when calling Draw
		void AddMotive();	// A motive can be any partition of a scene graph or the scene graph itself

		// How does the data oriented storage of a scene graph work?

	private:
		void drawMotive();
		void drawObject();
};