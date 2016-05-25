class Card < ActiveRecord::Base
  belongs_to :usuario
  has_many :logs
  
  validates :codigo, :activa, presence: {message: ": Campo obligatorio"}
  validates :codigo, length: {is: 4, message: ": Debe tener 4 dígitos"}
  validates :codigo, format: {with: /[0-9A-F]{4}/, message: ": Formato incorrecto"}
end
