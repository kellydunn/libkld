```
 ___        __       __       ___       __     
/\_ \    __/\ \     /\ \     /\_ \     /\ \    
\//\ \  /\_\ \ \____\ \ \/'\ \//\ \    \_\ \   
  \ \ \ \/\ \ \ '__`\\ \ , <   \ \ \   /'_` \  
   \_\ \_\ \ \ \ \L\ \\ \ \\`\  \_\ \_/\ \L\ \ 
   /\____\\ \_\ \_,__/ \ \_\ \_\/\____\ \___,_\
   \/____/ \/_/\/___/   \/_/\/_/\/____/\/__,_ /
                                               
```

# what

Rewriting common C structs in my side projects is getting a little tiresome, so I thought I'd have a single place where I keep my data structure implementations.  It's also good practice.

# installation

```
git clone git@github.com/kellydunn/libkld
cd libkld
make 
sudo make install
```

This will result in a static library: `/usr/lib/libkld.a`

# structs

Currently, `libkld` has the following data structures:

  - list

# documentation

I'm currently investigating the best optoin for documenting C projects.  The two I'm evaluating now are Doxygen and [docurium](https://github.com/libgit2/docurium). 