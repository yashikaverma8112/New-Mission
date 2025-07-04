module.exports={
    name:'Learn nodejs',
    sum:function(a,b){
    console.log(a+b);
}}


module.exports.indirectExport = function(){
    console.log("function of indirect export");
}
module.exports.indirectExportValue = 123;


