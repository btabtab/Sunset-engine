typedef struct Object
{
    /*
    */
    void* ptr_model_data;
    
    /*
        This points to a structure that will
        give Objects their own data so that
        the user can customize the Object.
    */
    void* ptr_custom_data;

    //Flags
    /*
        Tracks wether or not the object
        should be removed from memory.
            true: keep in memory,
            false: remove from memory
    */
    bool keep_in_memory;

    /*
        This points to a structure that will point to
        a structure so that the user can give Objects
        their own custom flag sets.
    */
    void* ptr_custom_flag_set;
}
Object;
