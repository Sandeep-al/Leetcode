# Write your MySQL query statement below
select Product.product_name,Sales.year,Sales.price
From Sales inner join Product
ON Sales.product_id=Product.product_id;