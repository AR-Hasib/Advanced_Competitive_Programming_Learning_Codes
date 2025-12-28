/* lambda function template type 1: (slower execution)
function<return_type(parameters)> function_name = [&] (parameters) {
    expressions;
};
function_name(arguments);

type 2:(faster)
auto function_name = [&] (auto &&function_name, parameters) -> return_type{
    expressions;
    function_name(function_name, parameters);
}
function_name(function_name, parameters);
*/