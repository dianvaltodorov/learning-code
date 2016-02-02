/*
 * Complete the function below.
 */
function validateForm(form_params) {
    var errors = {};
    var email_regex="/^([a-z0-9]{5,})$/";
    var title = form_params['title'];
    if (title.length > 20)
        errors['title'] = "title is too long";

    var description = form_params['description'];
    if (description.length > 200)
        errors['description'] = "description is too long";

    var lecturer_name = form_params['lecturer_name'];
    if (lecturer_name.length > 20)
        errors['lecturer_name'] = "lecturer_name is too long";

    var type = form_params['type'];
    if (!(type == "elective" || type == "mandatory"))
        errors['type'] = "lecturer_name is too long";

    var program = form_params['program'];
    if (!(program == "bachelor" || program == "master"))
        errors['program'] = "course can only take value bachelor or master";


    var course = form_params['course'];
    if (course < 0 || course > 4)
        errors['course'] = "course is out of bounds";

    var lecturer_email = form_params['lecturer_email'];
    if (!(/^[-a-z0-9~!$%^&*_=+}{\'?]+(\.[-a-z0-9~!$%^&*_=+}{\'?]+)*@([a-z0-9_][-a-z0-9_]*(\.[-a-z0-9_]+)*\.(aero|arpa|biz|com|coop|edu|gov|info|int|mil|museum|name|net|org|pro|travel|mobi|[a-z][a-z])|([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}))(:[0-9]{1,5})?$/i.test(lecturer_email)))
        errors['lecturer_email'] = "lecturer email is wrong";

    return errors;

}
