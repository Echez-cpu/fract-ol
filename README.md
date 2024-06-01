![Screenshot from 2024-06-01 14-23-29](https://github.com/Echez-cpu/fract-ol/assets/129857369/6e08edbc-6b1c-482b-9dda-9e9d75c91c29)


This project was challenging, though enjoyable to complete, and the end result is so worth it!
I completed the mandatory and 4/5 of the bonus (everything except the third fractal). Note: The zoom centering the cursor is not perfect - please share if you figure it out!


The versions included are /linux /macos_commented and /norminette


Here is the outline of how I tackled fract-ol:


Step 1: Learn the MiniLibX graphical library
Step 2: Learn the Complex numbers notion


Step 3: Learn how Fractals work


Step 4: Learn about Event handling in the context of the project


Step 5: Plan the structure of directories and files


Step 6: Implement fract-ol


Step 7: Test fract-ol against the evaluation checklist
I worked with Linux, and once the program functioned, I translated the code to work on MacOS. See notes here: Differences between Linux and MacOS (though it might not make sense before delving in to the project's implementation).
See references for resources use




🔷 Step 1: Learn the MiniLibX graphical library
Getting to know the basics of this graphical library with no prior knowledge can be overwhelming (atleast for me). It made more sense the more I wrote and tested our code for fractol, and in the end, it wasn't so intimidating. My big take is, it's a basic graphics library, with basic functions, and it's got nothing on you! Below is the sequence of the functions I learned:




mlx_init()

mlx_new_window()

mlx_destroy_window()

mlx_destroy_display()

mlx_new_image()

mlx_destroy_image()

mlx_get_data_addr()

mlx_pixel_put()

mlx_put_image_to_window()

mlx_hook()

mlx_loop()


🔸 mlx_init()








Initiates our program by establising a connection to the MLX graphical system.
This is important for our program to be able to access to the resources needed for graphics rendering.
In the context of fractol, we will have a data structure, which will contain an element e.g. void	*mlx_connect;
It stores the pointer returned from the mlx_init() function that makes the connection to the MLX system.
Now that we have a connection established, and one that is unique to our program, the pointer to this connection will be taken as a parameter for many minilibx functions.





🔸 mlx_new_window()
Is responsible for creating a window for our program. I imagine this as like, creating a blank canvas and frame before we can paint on it.
We can define for it, its WIDTH and HEIGHT dimensions, and a window name, and it'll display it accordingly.
In the context of fractol, our data structure will contain an element e.g. void	*window;
It stores the pointer returned from mlx_new_window() after having created a window for us.
Similarly to the *mlx_connect pointer, the *window pointer will also be taken as a paramenter for each function that interacts with the window.





🔸 mlx_destroy_window()

Is used to close, and destroy a window that has not been created successfully.
It frees up any memory needed and clears the relevant resources accociated with the attempted window creation.




🔸 mlx_destroy_display()

Is used to close a window. The difference from mlx_destroy_window() is that it doesn't free up and release resources.
I used this function when working with Linux, but after working on MacOS, I realised it isn't necessary, and I could just use the mlx_destroy_window in its place.
The minilibx MacOS version does not have the mlx_destroy_display() defined.




🔸 mlx_new_image()

Creates a new image.
At first I was confused with what the difference was between this function, and the mlx_new_window, because you could draw pixels on either image, or window.
The difference is, this image acts like a buffer. We're drawing pixels on a image in memory, whereas, without this image, we're drawing pixels directly on the window.
I imagine the image as like, a "draft canvas" - a seperate canvas to paint on, and once we're happy with it, we place the whole painting on top of our window as a final product.
In the context of fractol, we want to draw our fractal on a buffer image first, off screen, before we display it on our window for the user to see.
This is important, because, without a buffer, drawing one pixel at a time directly on the window can be visibly distracting and slow, and the user will see this in "real time" rather than seeing a completed drawing at once.
Our data structure will contain an element e.g. void	*img;
It stores the pointer returned from mlx_new_image() after having created an image for us.
The image buffer will be of the same WIDTH and HEIGHT dimension as our window.





🔸 mlx_destroy_image()

If the new image creation is unsuccessfull, this function is used to destroy it and free memory associated with it.





🔸 mlx_get_data_addr()

If the new image creation is successfull, this function retrieves information about the newly created image, and updates the relevent data elements of our data structure for fractol:
char	*img_addr; stores the address of the image
int	img_bpp; stores the number of bits per pixel in the image
int	img_line; stores the size of each row in bytes
int	img_endian; stores information about the endianness of the image data
As long as we define the data elements for the image address, bpp, line, and endian in our struct, we don't really need to mind the endian data - minilibx will take care of it.





🔸 mlx_pixel_put()

Is responsible for drawing a pixel directly on the window.
Recall, we said that drawing pixels directly on the window is inefficient, and extremely slow. It invloves sending a request to the X server (Windows) or the WindowServer (MacOS) for each pixel, which can result in significant overhead.
For this reason, we create our own pixel_put() function that can update all the pixel data via a buffer before displaying the entire updated image in a single operation with mlx_put_image_to_window().
For our fractol, we will create our own pixel_put function called ft_pixel_put
It calculates where we want each pixel to be placed on our image (buffer), and colours it.




🔸 mlx_put_image_to_window()

After our ft_pixel_put() function has set all the data for all the pixels of our image, this function renders and displays our image on the window, our final "canvas".




🔸 mlx_hook()

Is responsible for handling key and mouse events, used to interact with our window.
It takes in as parameters:
the pointer to our window
an int code for the event, for example:
the code for a key event is KeyPress for Linux and 2 for MacOS
the code for a mouse event is ButtonPress for Linux and 4 for MacOS
the code for a close (ESC or X) event is DestroyNotify for Linux and 17 for MacOS
an int code for the event mask, which captures the specific event types, for example:
the event mask for a key event is KeyPressMask for Linux
the event mask for a mouse event is ButtonPressMask for Linux
the event mask for a close (ESC or X) event is StructureNotifyMask for Linux
MacOS doesn't use this parameter, so we can set it to 0.
a user-defined function to handle a specific event type, e.g.
handle_key()
handle_mouse()
clean_exit()
a pointer to our data structure




🔸 mlx_loop()

keeps the application running and responsive, as without it, our program would finish executing without capturing user input events like keyboard presses, or mouse movements. It would simply execute the code that sets up the window and be non-interactive.
